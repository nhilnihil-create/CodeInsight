#include <bits/stdc++.h>
 
using namespace std;
 
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
 
const long long INF = 1LL << 60;
#define PI 3.14159265359 
 
template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}
 
int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
 
long long lcm (int a, int b){
    return  (long long) a*b /gcd(a,b);
}



int main(){
    vector<int>a(5);

    rep(i,5)cin >> a[i];

    int k;
    cin >> k;

    bool can = true;

    if(a[1]-a[0] >k || a[2]-a[0] > k ||a[3]-a[0] > k ||a[4]-a[0] > k )can = false;
    else if(a[2]-a[1] >k || a[3]-a[1] > k ||a[4]-a[1] > k )can = false;
    else if(a[3]-a[2] >k || a[4]-a[2] > k )can = false;
    else if(a[4]-a[3] >k) can = false; 

    if(can) cout << "Yay!" << endl;
    else cout << ":(" << endl;
}
