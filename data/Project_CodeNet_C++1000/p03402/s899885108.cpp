#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;


void solve(long long A, long long B){
    vector<string> left(25*100), right(25*100);
    auto cnt=B-1;
    for(int i=0; i<25*100; i++){
        if((i/25)%2==0 && cnt>0){
            left[i]="#.";
            cnt--;
        }
        else left[i] = "..";
    }
    cnt=A-1;
    for(int i=0; i<25*100; i++){
        if((i/25)%2==0 && cnt>0){
            right[i]="#.";
            cnt--;
        }
        else right[i] = "##";
    }
    cout << 100 << " " << 100 << endl;
    for(int h=0; h<100; h++){
        for(int w=0; w<50; w++){
            if(w<25){
                cout << left[25*h+w];
            }else{
                cout << right[25*h+(w%25)];
            }
        }
        cout << endl;
    }
}

int main(){
    long long A;
    scanf("%lld",&A);
    long long B;
    scanf("%lld",&B);
    solve(A, B);
    return 0;
}
