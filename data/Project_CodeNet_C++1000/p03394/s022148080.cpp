#include<iostream>
#include<cstdio>
#include<set>
using namespace std;


set<int> ans;

int main(){
    int N;
    cin >> N;
    
    int ans_[] = {2, 5, 63, 20, 30};
    if(N <= 5){
        for(int i = 0; i < N; i++){
            if(i) cout << " ";
            cout << ans_[i];
        }
        cout << endl;
        return 0;
    }

    long long sum = 0;
    int breaked;
    for(int i = 1; i <= 30000; i++){
        if(i % 2 == 0 || i % 3 == 0){
            ans.insert(i);
            sum += i;
        }
        if(ans.size() >= N){
            breaked = i;
            break;
        }
    }
    if(sum % 6 == 2){
        ans.erase(8);
        ans.insert(breaked/6*6 + 6);
    }else if(sum % 6 == 3){
        ans.erase(9);
        ans.insert(breaked/6*6 + 6);
    }else if(sum % 6 == 5){
        ans.erase(9);
        ans.insert((breaked-4)/6*6 + 6 + 4);
    }

    for(auto it = ans.begin(); it != ans.end(); it++){
        if(it != ans.begin()) cout << " ";
        cout << *it;
    }
    cout << endl;
    
}