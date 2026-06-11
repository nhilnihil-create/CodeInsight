#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<int> aloneNum;

int dfs(int t, int S){
    if(t > 12){
        int retVal =12;
        vector<int> selcted;
        for(int i=0;i<24;i++){
            if(S &(1<<i)){
                selcted.push_back(i);
            }
        }
        selcted.push_back(24);
        // cerr << "cal" << endl;
        for(int i=0;i<selcted.size();i++){
            // cerr << selcted[i] << endl;
            if(i==0){
                continue;
            }
            int temp = selcted[i]-selcted[i-1];
            retVal = min(retVal,min(temp,24-temp));
        }
        return retVal;
    }
    if(aloneNum.find(t) != aloneNum.end()){
        return max(dfs(t+1,S|(1<<t)),dfs(t+1,S|(1<<(24-t))));
    }
    return dfs(t+1,S);

}

int main(){
    int N;
    cin >> N;
    vector<int> D(N+1);
     vector<int> num(13,0);
    for(int i=0;i<N;i++){
        cin >> D[i];
        num[D[i]] ++;
    }
    num[0]++;
    if(num[0] >1 || num[12] >1){
        cout << 0 << endl;
        return 0;
    }
    
    int S =1;
    for(int i=1;i<=12;i++){
        if(num[i] >2){
            cout << 0 << endl;
            return 0;
        }
        if(num[i] == 2){
            S |= (1<<i);
            S |= (1<<(24-i));
        }else if(num[i] == 1){
            aloneNum.insert(i);
        }
    }

    // cerr << bitset<24>(S) << endl;

    cout << dfs(0,S) << endl;
   
    return 0;
}