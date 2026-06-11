#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(void){
    long long n,x;
    cin >> n >> x;
    vector<long long> vec(n);
    long long count2 = 0;
    long long sum = 0;
    rep(i,n){
        cin >> vec.at(i);
        sum += vec.at(i);
    }
    
    sort(vec.begin(),vec.end());

    long long count = 0;
    rep(i,n){

        if(sum < x){
            cout << n-1 << endl;
            return 0;
        }
        
        else if(sum > x){
            count = 0;
            for(int i=0;i<n;i++){
                if(x >= vec.at(i)){
                    x -= vec.at(i);
                    count++;
                }
            }
            cout << count << endl;
            return 0;
        }

        else{
            cout << n << endl;
            return 0;
        }
    }
    
}