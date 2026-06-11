#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<stack>
#include<list>
#include<map>
#include<deque>
#include<math.h>
using namespace std;
#define ll long long
int main(){
    ll N;
    cin >> N;
    ll m=0,a=0,r=0,c=0,h=0;
    ll i;
    string s;
    for(i=0;i<N;i++){
        cin >> s;
        if(s[0]=='M')m++;
        if(s[0]=='A')a++;
        if(s[0]=='R')r++;
        if(s[0]=='C')c++;
        if(s[0]=='H')h++;
    }
    cout << m*a*r+m*a*c+m*a*h+m*r*c+m*r*h+m*c*h+a*r*c+a*r*h+a*c*h+r*c*h<<endl;
    return 0;
}
