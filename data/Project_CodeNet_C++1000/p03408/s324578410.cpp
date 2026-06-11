#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N,M;
    cin >> N;
    vector<string> S(N);
    for (int i=0;i<N;i++) {
        cin >> S.at(i);
    }
    cin >> M;
    vector<string> T(M);
    for (int i=0;i<M;i++) {
        cin >> T.at(i);
    }
    
    int count=0;
    int point=0;
    
    for (int i=0;i<N;i++) {
        string word = S.at(i);
        count = 0;
        for (int j=0;j<N;j++) {
            if(word == S.at(j)) {
                count++;
            }
            
        }
        for (int k=0;k<M;k++) {
                if(word == T.at(k)) {
                    count--;
                }
            }
        point = max(point,count);
    }
    cout << point << endl;
    
   }

 