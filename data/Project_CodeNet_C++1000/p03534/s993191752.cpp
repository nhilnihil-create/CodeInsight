#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string s; cin >> s;
    int N = s.length();

    int cnt[3] = {0,0,0};
    char abc[3] = {'a', 'b', 'c'};

    for(int i=0;i<N;i++){
        for(int k=0;k<3;k++){
            if(s[i] == abc[k]){
                cnt[k]++;
            }
        }
    }

    sort(cnt, cnt+3);
    if(cnt[2] - cnt[0] >= 2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;

}