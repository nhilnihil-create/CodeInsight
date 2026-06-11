#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define DEBUG 0 
#define LIMIT (LONG_MAX / 10)
#define POSITIVE_LAST_D (LONG_MAX % 10)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

int main(){
    //identify a prime number
    int mm=100005;
    vector<int> is_prime(mm,1);
    is_prime[0]=0;
    is_prime[1]=0;
    for(int i=2;i*i<mm;++i){
        if(!is_prime[i])continue;
        for(int j=i*2;j<mm;j+=i)is_prime[j]=0;
    }
    //identify a number like 2017
    vector<int> like_2017(mm,0);
    rep(i,mm){
        if(is_prime[i]&&is_prime[(i+1)/2])like_2017[i]=1;
    }
    //get the cumulative sum
    vector<int> csum(mm,0);
    csum[0]=0;
    rep(i,mm){
        csum[i+1]=csum[i]+like_2017[i];
    }

    int q;
    cin>>q;
    vector<int> l(q),r(q);
    rep(i,q){
        cin>>l[i]>>r[i];
    }
    rep(i,q){
        cout<<csum[r[i]+1]-csum[l[i]]<<endl;
    }




}