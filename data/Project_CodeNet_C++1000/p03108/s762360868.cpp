#include <bits/stdc++.h>
using namespace std;

long n,m;long parent[100005];long size[100005];

struct Node{
  long from,to;
};

long getparent(long id) {
  if (parent[id]==id) return id;
  else {
    return getparent(parent[id]);
  }
}

bool issame(long a,long b) {
  return getparent(a)==getparent(b);
}

void unite(long a,long b) {
  long parent_a=getparent(a);
  long parent_b=getparent(b);
  if (parent_a==parent_b) return;
  else {
    if (size[parent_a]<size[parent_b]) {
      parent[parent_a]=parent_b;
      size[parent_b]+=size[parent_a];size[parent_a]=0L;
    }
    else {
      parent[parent_b]=parent_a;
      size[parent_a]+=size[parent_b];size[parent_b]=0L;
    }
  }
}

long getsize(long a) {
  long parent_a=getparent(a);
  return size[parent_a];
}

int main() {
  cin >> n >> m;
  Node nodes[m];long count[m];count[m-1]=0L;
  for (int i=0;i<m;i++) {
    cin >> nodes[i].from >> nodes[i].to;
  }
  for (int i=0;i<n;i++) {
    parent[i]=i;
    size[i]=1L;
  }
  for (int i=m-1;i>0;i--) {
    if (issame(nodes[i].from,nodes[i].to)) {
      count[i-1]=count[i];
    }
    else {
      count[i-1]=count[i]+getsize(nodes[i].from)*getsize(nodes[i].to);
      unite(nodes[i].from,nodes[i].to);
    }
  }
  long base=n*(n-1L)/2L;
  for (int i=0;i<m;i++) {
    cout << base-count[i] << endl;
  }
}