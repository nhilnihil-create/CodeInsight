#include <bits/stdc++.h>
using namespace std;
vector <int> dish(5);
vector <int> order;
int ans = INT_MAX;
int getTime(){
    int ret = 0;
    for(int i = 0; i < 4; i++){
        ret+=dish[order[i]];
        if(ret%10!=0){
            ret+=(10-ret%10);
        }
        //cout << ret << " ";
    }
    ret+=dish[order[4]];
    //cout << ret << endl;
    return ret;
}
bool isValid(){
    for(int i = 0; i < 5; i++){
        for(int j = i+1; j < 5; j++){
            if(i!=j){
                if(order[i]==order[j]){
                    return false;
                }
            }
        }
    }
    return true;
}
void dfs(int index){
    order.push_back(index);
    if(order.size()==5){
        if(isValid()){
            for(int i = 0; i < 5; i++){
                //cout << dish[order[i]] << " ";
            }
            //cout << endl;
            //cout << getTime() << endl;
            ans = min(ans,getTime());
        }
        return;
    }
    for(int i = 0; i < 5; i++){
        dfs(i);
        order.pop_back();
    }
}
int main(){
    for(int i = 0; i < 5; i++){
        cin >> dish[i];
    }
    for(int i = 0; i < 5; i++){
        dfs(i);
        order.pop_back();
    }
    cout << ans << endl;
    return 0;
}