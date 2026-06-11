#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;

void del(int x){
    for(int i = 0 ; i < n ; i++){
        if(a[i] == x){
            a.erase(a.begin() + i);
            return;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if(n == 3) finish("2 5 63");
    if(n == 4) finish("2 5 20 63");
    if(n == 5) finish("2 5 20 30 63");
    int sum = 0;
    int cur = 1;
    while((int)a.size() < n){
        if(cur % 2 && cur % 3){
            cur++;
            continue;
        }
        a.push_back(cur);
        sum += cur;
        sum %= 6;
        cur++;
    }
    if(sum == 2){
        del(8);
        while(cur % 6) cur++;
        a.push_back(cur);
    }
    else if(sum == 3){
        del(9);
        while(cur % 6) cur++;
        a.push_back(cur);
    }
    else if(sum == 5){
        del(9);
        while(cur % 6 != 4) cur++;
        a.push_back(cur);
    }
    for(auto &i : a) cout << i << " ";
    cout << endl;
}
