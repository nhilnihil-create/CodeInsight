#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n,q;
    string s;
    cin >> n >> q >> s;
    vector<pair<char,char>> v(q);//呪文を格納
    int l=-1,r=s.size();//lbは左に落ちるゴレムのうち最も右にあるやつ(left border)
    for(int i=0;i < v.size();i++){
        cin >> v.at(i).first >> v.at(i).second;
    }

    reverse(v.begin(),v.end());//逆から実行して、どこまで行くか調べればok(追い越さないので)

    //何回も書くvの要素は置換しておく

    for(int j=0;j < v.size();j++){ 
        
        if(v.at(j).second == 'R'){
            if(r-1 >= 0 && v.at(j).first==s.at(r-1)){
                r--;
            }
            if(l-1>=-1 && v.at(j).first==s.at(l)){
                l--;//すでにいなかったら一つ戻る
            }
        }else{//Lの時
            if(r+1 <= s.size() && v.at(j).first==s.at(r)){
                r++;//既にいない場合
            }
            if(l+1<s.size() && v.at(j).first==s.at(l+1)){
                l++;
            }   
        }
    }
    
        cout << r-l-1 << endl;

}