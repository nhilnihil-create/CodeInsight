#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool revp2(const pair<ll,ll>&a,const pair<ll,ll>&b){return a.first>b.first;}
bool revp3(const pair<ll,ll>&a,const pair<ll,ll>&b){if(a.first==b.first)return a.second<b.second;
return a.first>b.first;}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll l1[4],s=0;
    cin>>l1[1]>>l1[2]>>l1[3];
    sort(l1+1,l1+3+1);
    ll jo=0,bij=0;
    for(int i=1;i<=3;i++)if(l1[i]&1)bij++;
    jo=3-bij;//cout<<jo<<endl;
    if(jo==3||bij==3)cout<<((l1[2]-l1[1])/2)+l1[3]-l1[2];
    else if(jo==2){
        for(int i=1;i<=3;i++){
            if(l1[i]%2==0)l1[i]++;
            //cout<<l1[i]<<endl;
        }
        s+=1;
        s+=((l1[2]-l1[1])/2)+l1[3]-l1[2];
        cout<<s;
    }
    else if(bij==2){
        for(int i=1;i<=3;i++){
            if(l1[i]%2!=0)l1[i]++;
        }
        s++;
        s+=((l1[2]-l1[1])/2)+l1[3]-l1[2];
        cout<<s;
    }
}
