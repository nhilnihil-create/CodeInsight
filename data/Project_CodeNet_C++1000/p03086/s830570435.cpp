#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int N=S.size();
    int ans=0;
    int count=0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N-i; j++){
            for(int k=0; k<i+1; k++){
                if(S.at(j+k)!='A'&&S.at(j+k)!='C'&&S.at(j+k)!='G'&&S.at(j+k)!='T'){
                count=1;
                break;
            }
            
            }
            if(count==0){
                ans=i+1;
                break;
            }
            count=0;
        }
        count=0;
    }

    cout << ans << endl;
}
