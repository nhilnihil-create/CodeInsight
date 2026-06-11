#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,fl_ab = 0,first_b = 0,last_a = 0,ab = 0;
    cin >> n;
    vector<string> s(n);
    for(int i = 0;i < n;i++){
        cin >> s[i];
        for(int j = 1;j < (int)s[i].size();j++){
            if(s[i][j - 1] == 'A' && s[i][j] == 'B')ab++;
        }
        if(s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A')fl_ab++;
        else if(s[i][0] == 'B')first_b++;
        else if(s[i][s[i].size() - 1] == 'A')last_a++;
    }
    if(fl_ab > 0){
        ab += fl_ab - 1;
        if(first_b > 0){
            ab++;
            first_b--;
        }
        if(last_a > 0){
            ab++;
            last_a--;
        }
    }
    ab += min(first_b,last_a);

    cout << ab << endl;
}