#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
const double pi = acos(-1.);
//printf(%.12lf\n,mid);
// __builtin_popcount(int) count 1's in binary
// get decimal part of number
/*
double intpart;
double thiss = modf((double)(n*m)/(double)k, &intpart);
*/
// round = (int)(num+.5)
long long mod = 1000000007;
 
// 32 mil = ~1 sec 
long long mymod(long long num){
  if (num< 0 && !(num%mod == 0)){
    if (mod == 1){
      return 0;
    }
    return mod-abs(num)%mod;
  }else{
    return num%mod;
  }
}
 
/*string sentence = And I feel fine...;
    istringstream iss(sentence);
*/  
 
double eps = .000000001;
vector<int> graph[100001];
bool colors[100001];
bool vis[100001];
bool good = true;
void color(int node, bool last){
    if (!good){
        return;
    }
    if (vis[node]){
        if (colors[node] != last){
            good = false;
        }
        return;
    }
    vis[node] = true;
    colors[node] = last;
    for (int i : graph[node]){
        color(i, !last);
    }
}
int main ()
{
  prep();
  long long n, m;
  cin >> n >> m;
  
  for (int i=0; i<m; i++){
      int a, b;
      cin >> a >> b;
      graph[a].push_back(b);
      graph[b].push_back(a);
  }
  color(1, 1);
  if (!good){
      cout << n*(n-1)/2-m;
      return 0;
  }
  long long white = 0;
  long long black = 0;
  for (int i=1; i<=n; i++){
      if (colors[i]){
          white++;
      }else{
          black++;
      }
      //cout << colors[i] << " ";
  }
  cout << white*black-m;
  return 0; 
}
