#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 char x,y;
 cin >> x >>y;
 int a=x-'A';
 int b=y-'A';
 if(a<b)cout << '<' <<endl;
 if(a>b)cout << '>' << endl;
 if(a==b)cout << '=' << endl;
}