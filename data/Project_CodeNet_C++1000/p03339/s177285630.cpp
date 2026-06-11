#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int totalE = 0;
    int totalW = 0;
    
    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == 'E')totalE++; // Eが合計何個あるかを数える
        else totalW++; // Wが合計何個あるかを数える
    }
    
    int ans = (int)s.size();
    
    int tempE = 0; // 現在地点より西にいる人のうち, 東を向いている人の数を表す
    int tempW = 0; // 現在地点より西にいる人のうち, 西を向いている人の数を表す
    
    for (int i = 0; i < (int)s.size(); i++){
        
        int reverseE = totalE - tempE; // リーダーより東にいて、東を向いている人を求める
        if (s[i] == 'E') reverseE--; // 現在地の人の向きを考慮する（この実装の場合）
        
        // reverseE + tempW
        // リーダーより西にいて、西を向いている人 + リーダーより東にいて、東を向いている人
        // これら２種類のパターンの人数が、reverseE + tempWである
        ans = min(ans, reverseE + tempW); 
        
        if (s[i] == 'W') tempW++;
        else tempE++;
    }
    
    cout << ans << endl;
}