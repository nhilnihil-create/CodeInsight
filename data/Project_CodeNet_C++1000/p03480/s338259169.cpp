#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    // 左からl個ひっくり返したあとに左からk+1個ひっくり返すとk+1個目だけ反転できる。
    // より大きな数字は自由に使えるので、k+1番目以降は自由に操作できる。
    // 右からでも同じ。
    // lが文字列の半分より大きいと左から、右からのどちらにも当てはまらない領域が中央に現れる。
    // 〇〇〇◎◎〇〇〇
    // k=5のとき◎は自由に操作できない。なので揃ってないといけない。
    
    string s;
    cin >> s;

    
    int l = ( s.length() - 1) / 2;  
    int r = ( s.length()) / 2; 
    int k = ( s.length()) / 2; 
    int center = s[l];
    while(1){
        if((s[l] == center) && (s[r] == center)){
            k++;
            if(0 == l) break;
            l--;
            r++;
        }else{
            break;
        }
    }


    cout << k << endl;    
}