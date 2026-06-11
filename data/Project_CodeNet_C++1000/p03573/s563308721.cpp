#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 int a,b,c;
 cin >> a>>b>> c;
 if(a!=b && a!=c)cout << a << endl;
 else if(b!=c && b!=a)cout <<  b<< endl;
 else if(c!=a && c!=b)cout << c << endl;

}