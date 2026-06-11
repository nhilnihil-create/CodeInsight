#include <bits/stdc++.h>
using namespace std;

int n,m;int parent[50];int size[50];

struct Node {
  int from,to;
};

Node nodes[50];

int getparent(int id) {
  if (parent[id]==id) return id;
  else return getparent(parent[id]);
}

bool issame(int a,int b) {
  return getparent(a)==getparent(b);
}

void unite(int a,int b) {
  int parent_a=getparent(a);
  int parent_b=getparent(b);
  if (parent_a==parent_b) return;
  else {
    if (size[parent_a]<size[parent_b]) {
      parent[parent_a]=parent_b;
      size[parent_b]++;
    }
    else {
      parent[parent_b]=parent_a;
      size[parent_a]++;
    }
    return;
  }
}

int main() {
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int a,b;
    cin >> a >> b;a--;b--;
    nodes[i].from=a,nodes[i].to=b;
  }
  int count=m;
  for (int i=0;i<m;i++) {
    for (int j=0;j<n;j++) {
      parent[j]=j;
      size[j]=1;
    }
    for (int j=0;j<m;j++) {
      if (j!=i) {
        if (!issame(nodes[j].from,nodes[j].to)) {
        unite(nodes[j].from,nodes[j].to);
        }
      }
    }
    if (issame(nodes[i].from,nodes[i].to)) count--;
  }
  cout << count << endl;
}