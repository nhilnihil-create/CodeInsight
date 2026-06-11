#include <bits/stdc++.h>

using namespace std;

bool sosuu(long long int x){
    for(long long int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    int N;
    cin >> N;
    vector<int> ans;

    for(int i=2;ans.size()!=N;i++){
        if(sosuu(i)){
            if(i%5==1){
                ans.push_back(i);
            }
        }
    }

    for(int i=0;i<ans.size();i++){
        if(i==0){
            cout << ans[i];
        }else{
            cout << " " << ans[i];
        }
    }

    cout << endl;
}