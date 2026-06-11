

#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n;
    cin>>n;


    //問題案Dをmapに保存する。
    map<int, int>  d_map;
    for(int i=0;i<n;i++){
        int wk;
        cin>>wk;
        if(d_map.count(wk))
            d_map.at(wk)++;
        else
            d_map[wk]=1;
    }


    //難易度Tに合った問題案Dがあるか調べる。
    int m;
    cin>>m;
    bool flg=true;
    for(int i=0;i<m;i++){
        int t;
        cin>>t;
        if(d_map.count(t)){
            d_map.at(t)--;
            if(d_map.at(t)<0)
                flg=false;
        }
        else
            flg=false;
    }

    if(flg)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}