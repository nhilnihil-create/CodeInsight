#include <iostream>
#include <vector>
using namespace std;

int n,q;
string s;
vector<pair<char,char>> p(200100);

int del(int now){
    for(int i = 0;i < q;i++){
        if(s[now] == p[i].first){
            if(p[i].second == 'R') now++;
            else now--;
        }
        if(now < 0) return -1;
        if(now >= n) return 1;
    }
    return 0;
}

int main(void){
    cin >> n >> q >> s;
    for(int i = 0;i < q;i++){
        cin >> p[i].first >> p[i].second;
    }
    
    int left = -1,right = n+1,tmp;
    while(right-left > 1){
        int mid = (right+left)/2;
        if(del(mid) == -1) left = mid;
        else right = mid;
    }
    tmp = right;
    
    
    left = -1,right = n+1;
    int tmp2;
    while(right-left > 1){
        int mid = (right+left)/2;
        if(del(mid) == 1) right = mid;
        else left = mid;
    }
    tmp2 = right;
    
    cout << tmp2-tmp << endl;
    return 0;
}
