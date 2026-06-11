#include <bits/stdc++.h>
 
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int k, result = 0, ans = 0;
    int v[5];
    for(int i = 0; i < 5; i++){
        cin >> v[i];
    }

    cin >> k;

    for(int i = 0; i < 4; i++){
        for(int j = i+1; j < 5; j++){
            if(v[i] > v[j]){
                result = v[i] - v[j];
                if(result <= k)
                    ans++;
            }
            else{
                result = v[j] - v[i];
                if(result <= k)
                    ans++;
            }
            
        }
    }

    if(ans == 10) cout << "Yay!" << endl;
    else cout << ":(" << endl;
    
    
}