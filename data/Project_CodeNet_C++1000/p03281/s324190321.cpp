#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    int ans=0;
    int count=0;
    for(int i=1; i<N+1; i++){
        if(i%2==1){
            for(int j=1; j<i+1; j++){
                if(i%j==0) count++;
            }
            if(count==8) ans++;
        }
        count=0;
    }
    cout << ans << endl;
}

  


  