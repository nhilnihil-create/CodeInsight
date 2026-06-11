#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <iomanip>
#include <queue>
#include <algorithm>
#include<set>
using namespace std;

int main()
{
    long long int n,k;
    cin >> n >>k;
    vector<long long int> kazu(k+1,0);
    vector<long long int> pow2(k+1,0);
    pow2.at(0)=1;
    long long int maxn=n;
    for(int i=0;i<=k;i++){
        if(k%pow2.at(i)==0){
            kazu.at(i)=k/pow2.at(i);
        }else{
            kazu.at(i)=k/pow2.at(i)+1;
        }
        // cout << i << "," << kazu.at(i) << endl;
        if(kazu.at(i)==1){
            maxn=i;
            break;
        }
        pow2.at(i+1)=2*pow2.at(i);
        
    }
    // vector<long long int> bunshi(maxn+1);
    long long int bunshi=max((long long int)0,n-kazu.at(0)+1)*pow2.at(maxn);
    // cout << bunshi << endl;
    // bunshi.at(0)=;
    for(int i=1;i<=maxn;i++){
        bunshi+= max((long long int)0,min(n-kazu.at(i)+1,kazu.at(i-1)-kazu.at(i)))*pow2.at(maxn-i);
    }
    double ans = 1.0*bunshi/n/pow2.at(maxn);
    // cout << maxn << "," << ans << endl;
    // for(int i=1;i<maxn;i++){
    //     ans += 1.0*max(0,min(n-kazu.at(i)+1,kazu.at(i-1)-kazu.at(i)))/pow2.at(i)/n;
    // }
    cout<< fixed<<  setprecision(15)  << ans << endl;
    return 0;
}
