#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<long long> v;

long long erase(){

    long long match_index = -1;
    long long r = -1;

    for(long long i = 0; i < v.size(); i++){
        if(v[i] == i+1){
            match_index = i;
        }
    }
    if(match_index != -1){
        r = v[match_index];
        v.erase(v.begin()+match_index);
    }

    return r;
}

int main(){
    long long n;
    cin >> n;

    for(long long i = 0; i < n; i++){
        long long b;
        cin >> b;
        v.push_back(b);
    }

    vector<long long> ans;

    bool flag = true;
    for(long long i = 0; i < n; i++){
        long long r = erase();
        if(r == -1){
            flag = false;
            break;
        }
        ans.push_back(r);
    }

    if(flag == false){
        printf("-1\n");
        return 0;
    }

    for(long long i = ans.size()-1; i >= 0; i--){
        printf("%lld\n", ans[i]);
    }

    return 0;


}