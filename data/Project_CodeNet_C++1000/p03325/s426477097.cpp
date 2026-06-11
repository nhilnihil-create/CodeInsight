#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >>N;
    long long count =0;
    for(int i=0;i<N;i++){
        long long a;
        cin >>a;
        for(;;){
            if(a%2==1){
                break;
            }
            else {
                a/=2;
                count++;
            }
        }
    }
    cout <<count<<endl;
}