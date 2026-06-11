#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,ans=0;
    string A,B,C;
    cin >> N >> A >> B >> C;

    if(A == B && A == C){
        ans = 0;
    }else{
        for(int i = 0;i < N;i++){
            if(A.at(i) == B.at(i) && A.at(i) != C.at(i)){
                C.at(i) = A.at(i);
                ans++;
            }
            else if(A.at(i) != B.at(i) && A.at(i) == C.at(i)){
                B.at(i) = A.at(i);
                ans++;
            }
            else if(B.at(i) == C.at(i) && A.at(i) != C.at(i)){
                A.at(i) = B.at(i);
                ans++;
            }else if(A.at(i) == B.at(i) && A.at(i) == C.at(i)){
                continue;
            }
            else{
                B.at(i) = A.at(i);
                ans++;
                C.at(i) = A.at(i);
                ans++;
            }
        }
    }
    cout << ans << endl;
}