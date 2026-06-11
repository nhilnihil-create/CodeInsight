#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a;i < b;i++)
#define For(i, a) FOR(i, 0, a)
#define REV(i, a, b) for(int i = b-1;i >= a;i--)
#define Rev(i, a) REV(i, 0, a)
#define REP(a) For(i, a)
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pi;
typedef vector<int> vi;
void print_pair(pi a){
  cerr<<"("<<a.first<<", "<<a.second<<") ";
}
template<int T1, int T2>
void print_2d(int a[T1][T2], int x, int y){
  For(i, x){
    For(j, y){
      cerr<<a[i][j]<<" ";
    }
    cerr<<endl;
  }
}
template<class T>
void print_array(T a[],size_t n){
  cerr<<"array:";
  REP(n-1)cerr<<a[i]<<",";
  cerr<<a[n-1]<<endl;
}

int N;
ll cache[100000];

int main(){
  cin>>N;
  REP(100000)cache[i]=(i+1)*(i+2);
  N*=2;
  for (int i = 0; cache[i] <= N; i++) {
    if(N==cache[i]){
      cout<<"Yes"<<endl;
      cout<<i+2<<endl;
      vector<int> ans[i+2];
      int cur=1;
      For(j,i+2){
        For(k,i+1-j){
          ans[j].push_back(cur);
          ans[j+1+k].push_back(cur);
          cur++;
        }
      }
      For(j,i+2){
        cout<<ans[j].size();
        for(auto tmp:ans[j]){
          cout<<" "<<tmp;
        }
        cout<<endl;
      }
      return 0;
    }
  }
  cout<<"No"<<endl;
  return 0;
}

