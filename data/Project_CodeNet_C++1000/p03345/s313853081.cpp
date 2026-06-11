#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define faster ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
 
typedef vector<int> vi;;
typedef vector<ll> vll;

#define l() length()
#define sz() size()
 
#define b() begin()
#define e() end()
#define all(x) x.begin(), x.end()
 
#define pb(i) push_back(i)
#define PB() pop_back()
 
 
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define Fi first
#define Se second
 
const int maxx=1e6+9;
 
// Happy Coding!

struct Point{
public:
    int x,y;
    Point(int x,int y){
        this->x=x;
        this->y=y;
    }
};

double square(double x){return x*x;}
double distance(Point p1,Point p2){return sqrt( square(p1.x-p2.x) + square(p1.y-p2.y) );}

int factorial(int n){
    int f=1;
    for(int i=1;i<=n;i++){f*=i;}
    return f;
}
void solve(){
    
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    
    cout<<( (k%2==0) ? a-b : b-a )<<endl;
}

int main() {
    faster;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
	return 0;
}