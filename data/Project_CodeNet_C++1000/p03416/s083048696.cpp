#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <set>
#define ll long long
#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define sz(a) int((a).size())
#define shit while(t--)
#define fr for(int i=0;i<n;i++)
int maxo=1e9+7;
using namespace std;
int arr[95];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
int a,b,x=0;

cin>>a>>b;
for(int i=a;i<=b;i++){
int reversedInteger = 0, remainder, originalInteger,temp;
 
 
    originalInteger=i;
    temp=i;
    while( temp!=0 )
    {
        remainder = temp%10;
        reversedInteger = reversedInteger*10 + remainder;
        temp/= 10;
    }
    if (originalInteger == reversedInteger)
        x++;
}
cout<<x;
return 0;
}