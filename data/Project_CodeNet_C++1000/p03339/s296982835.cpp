#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define ll long long
using namespace std;
int main(){
    ll n;
    string s;
    cin>>n>>s;
    int e_num=0;
    int w_num=0;
    for(int i=0;i<n;i++){
        if('W'==s[i]){
            w_num++;
        }else{
            e_num++;
        }
    }
    int min=1000000;
    int wnow=0;
    int enow=0;
    for(int i=0;i<n;i++){
        if('E'==s[i]){
            enow++;
        }
        if(min>wnow+(e_num-enow)){
            min=wnow+(e_num-enow);
        };

        if('W'==s[i]){
            wnow++;
        }
    }
    cout<<min<<endl;
    return 0;
}