#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int get(int n){
    string ans;
    cout << n << endl;
    cin >> ans;
    if(ans == "Male"){
        return 1;
    }else if(ans == "Female"){
        return 2;
    }else if(ans == "Vacant"){
        return 0;
    }
}

int main(){
    int N;  cin >> N;
    vector<int> seat(N, -1);
    int l = 0, r = N-1;
    if(seat[l] == -1){
        seat[l] = get(l);
        if(seat[l] == 0){
            cout << l << endl;
            return 0;
        }
    }
    if(seat[r] == -1){
        seat[r] = get(r);
        if(seat[r] == 0){
            cout << r << endl;
            return 0;
        }
    }

    while(true){
        int m = (l+r)/2;
        if(seat[m] == -1){
            seat[m] = get(m);
            if(seat[m] == 0){
                cout << m << endl;
                return 0;
            }
        }
        if((m-l)%2 == 1 && seat[m] == seat[l]){
            r = m;
        }
        if((m-l)%2 == 0 && seat[m] != seat[l]){
            r = m;
        }
        if((r-m)%2 == 1 && seat[m] == seat[r]){
            l = m;
        }
        if((r-m)%2 == 0 && seat[m] != seat[r]){
            l = m;
        }
    }
}
