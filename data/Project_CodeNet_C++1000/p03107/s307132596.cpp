

#include <bits/stdc++.h>
#include <string.h>
#include <vector>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15
#define MOD 1000000007

int main(){

 string s;
 cin>>s;

 int len = s.length(),k=0;

 for(int i=0;i<len;i++){
    if(s[i] == '1')
        k++;
 }

 int zeros = len-k;

 if(k > zeros)
    cout<<zeros*2<<endl;
 else if(k < zeros)
    cout<<k*2<<endl;
  else if(k == zeros)
    cout<<k*2<<endl;


return 0;
}
