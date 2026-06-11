#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>

using namespace std;

typedef long long ll;
typedef vector <ll> v_ll;
typedef vector <vector <ll> > vv_ll;
typedef vector < pair <ll,ll> > vp_ll;
typedef pair <ll,ll> p_ll;

ll L;
int main(){
  cin >> L;
  ll L2=L;
  ll N=1,M=0;
  while (L2>1){
    if (L2%2==1){
      L2--;
      M++;
    }
    L2/=2;
    N++;
    M+=2;
  }
  L2=L;
  ll k=1;
  cout << N << " "<< M << endl;
  while (L2>1){
    if (L2%2==1){
      L2--;
      cout << k << " " << N << " " << L2 << endl;
    }
    L2/=2;
    cout << k << " " << k+1 << " " << 0 << endl;
    cout << k << " " << k+1 << " " << L2 << endl;
    k++;
  }

  return 0;
}
