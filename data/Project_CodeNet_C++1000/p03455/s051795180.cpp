#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define repd(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define forr(i,a,b) for(ll i=(a);i<=(b);i++)
#define ford(i,a,b) for(ll i=(a);i>=(b);i--)
#define all(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define size(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define MAXR 100000 //10^5:最大のrange(素数列挙などで使用)



int main(void) {
    long int a,ans=0,b,i;
    cin >> a;
    cin >> b;
    if(a*b % 2 == 0){
        cout << "Even" << "\n";
    }
    else{
        cout << "Odd" << "\n";
    }


    

  return 0;
}