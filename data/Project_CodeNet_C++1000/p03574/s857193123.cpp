#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w,cnt,l,el,c,ec,k;
    cin>>h>>w;
    char m[h+1][w+1];
    for(int i = 0;i<h;++i){
        if(i == 0){
            getchar();
        }
        cin.getline(m[i],100);
    }
    for(int i = 0;i<h;++i){
        
        for(int j = 0;j<w;++j){
            if(m[i][j] == '#'){
                continue;
            }
            cnt = 0;
            l = i-1;
            el = i+1;
            c = j-1;
            ec = j+1;
            if(i == 0){
                l = i;
            }
            if(i == h-1){
                el = h-1;
            }
            if(j == 0){
                c = j;
            }
            if(j == w-1){
                ec = j;
            }
            for(;l<=el;++l){
                for(k = c;k<=ec;++k){
                    if(l == i && k == j){
                        continue;
                    }
                    if(m[l][k] == '#'){
                        cnt++;
                    }
                }
            }
            m[i][j] = cnt+'0';
        }
    }
    for(int i = 0;i<h;++i){
        for(int j = 0;j<w;++j){
            cout<<m[i][j];
        }
        cout<<endl;
    }

    return 0;
}