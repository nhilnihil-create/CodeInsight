
#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
int n;
cin>>n;
int num[1000];
for(int i = 0;i<n;i++)cin>>num[i];
int all = 1;
int bad = 1;
for(int i =0;i<n;i++){
    all*=3;
if(num[i]%2==0)bad*=2;

}
cout<<all-bad<<endl;

}
