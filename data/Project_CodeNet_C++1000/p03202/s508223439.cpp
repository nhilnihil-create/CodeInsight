#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <cassert>
#include <map>
#define maxn 200005

using namespace std;
typedef long long ll;
const int LEN = 100000;

struct fastio{
  int it,len;
  char s[100005];
  fastio(){
	  it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    len = fread(s,1,100000,stdin);
    it = 0;
    return len ? s[it++] : EOF;
  }
  void put(char c){
    if(it == LEN) fwrite(s,1,LEN,stdout), it = 0;
    s[it++] = c;
  }
  void flush(){
    fwrite(s,1,it,stdout);
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get()) res = res * 10 + (c - '0');
  return sig * res;
}
inline void putint(int x,char c){
  if(x == 0) bufo.put('0');
  if(x < 0) bufo.put('-'), x = -x;
  char s[15]; int k = 0;
  while(x){
    s[++k] = x % 10 + '0';
    x /= 10;
  }
  for(;k >= 1;k--) bufo.put(s[k]);
  bufo.put(c);
}

int n,a[maxn];
map <int,int> cur;
typedef map<int,int>::iterator Ite;
bool check(int x){
  if(x == 1){
    for(int i = 1;i < n;i++) if(a[i + 1] <= a[i]) return false;
    return true;
  }
  cur.clear();
  for(int i = 1;i <= n;i++){
    if(a[i] <= a[i - 1]){
      if(!cur.empty()){
        Ite it = cur.end();
        vector <Ite> vec;
        for(it--;it != cur.begin() && (it -> first) > a[i];it--) vec.push_back(it);
        for(int j = 0;j < (int)vec.size();j++) cur.erase(vec[j]);
        if(cur.begin() -> first > a[i]) cur.erase(cur.begin());
      }
      int tmp = a[i];
      while(tmp && cur.find(tmp) != cur.end() && cur[tmp] == x - 1){
        cur[tmp] = 0;
        tmp--;
      }
      if(!tmp) return false;
      if(cur.find(tmp) != cur.end()) cur[tmp]++;
      else cur[tmp] = 1;
    }
  }
  return true;
}
int main(){
  n = getint();
  for(int i = 1;i <= n;i++) a[i] = getint();
  int lb = 1, rb = n;
  while(lb < rb){
    int mid = (lb + rb) >> 1;
    if(check(mid)) rb = mid;
    else lb = mid + 1;
  }
  printf("%d\n",lb);
  return 0;
}
