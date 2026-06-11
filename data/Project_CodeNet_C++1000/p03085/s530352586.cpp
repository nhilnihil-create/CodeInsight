#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}
 
int main()
{
    char b;
  	cin >> b;
  	switch(b){
      case'A':
        cout << 'T' << endl;
        break;
      case'T':
        cout << 'A' << endl;
        break;
      case'C':
        cout << 'G' << endl;
        break;
      case'G':
        cout << 'C' << endl;
        break;
    }
  	return 0;
}