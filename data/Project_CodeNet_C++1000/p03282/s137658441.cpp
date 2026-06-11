#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define sz 100005

char f,g;
bool flag;
string s;
vector < int > v,va,vb;
int arr[sz],brr[sz],crr[sz];



int main(){

    priority_queue< long long int > pq;
    long long int n,m, i,j,k, x,y,z;
    cin>>s>>k;
    for(i=0; i<s.size(); i++){
        if(i+1==k || s[i]!='1'){
            cout<<s[i]<<endl;
            break;}
    }


    return 0;

}