//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>

/*
#include<boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/rational.hpp>
namespace mp = boost::multiprecision;
using Real = mp::number<mp::cpp_dec_float<1024>>;
using Bint = mp::cpp_int;
*/

using namespace std;

#define int long long
#define REP(i,s,e) for((i)=(s);(i)<(e);(i)++)
#define RREP(i,s,e) for((i)=((s)-1);(i)>=(e);(i)--)
#define FOR(i,n) for((i)=(0);(i)<(n);(i)++)
#define RFOR(i,n) for((i)=((n)-1);(i)>=(0);(i)--)
#define MOD 1000000007

signed main(){
    int N;
    cin>>N;

    int ans=LLONG_MAX;
    for(int i=1;i<N;i++){
        int n=i;
        int k=N-i;
        int c=0;
        while(n!=0){
            c+=n%10;
            n/=10;
        }
        while(k!=0){
            c+=k%10;
            k/=10;
        }
        ans=min(ans,c);
    }
    cout<<ans<<endl;
}

