#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repeq(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define rep1(i,x,n) for(int (i)=(x);(i)<(int)(n);(i)++)
#define rep1eq(i,x,n) for(int (i)=(x);(i)<=(int)(n);(i)++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
using namespace std;
using ll = long long;
using Int = long long;

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e8;
typedef pair<int,int> P;
typedef std::priority_queue<int> IntPrioQueue;
typedef std::priority_queue<int, std::vector<int>, std::greater<int> > IntReversePrioQueue;

//少数点表示
//cout << std::fixed << std::setprecision(14) << 値

int main(){
    cin.tie( 0 ); ios::sync_with_stdio( false );
    string s;
    cin >> s;
    int y = stoi(s.substr(0,4));
    int m = stoi(s.substr(5,2));
    int d = stoi(s.substr(8,2));

    if(y>2019 || (y==2019 && m>4)) cout << "TBD" << endl;
    else cout << "Heisei" << endl;

    return 0;
    
}