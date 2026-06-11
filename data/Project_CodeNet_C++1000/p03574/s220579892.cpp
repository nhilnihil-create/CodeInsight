#include<bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin>>h>>w;
    vector<string> str(h);
    for(int i=0;i<h;i++){
        cin>>str[i];
    }
    for(int r=0;r<h;r++){
        for(int c=0;c<w;c++){
            if(str[r].at(c)=='.'){
                int tmp=0;
                if(r!=0&&c!=0)if(str[r-1].at(c-1)=='#')tmp++;//左上
                if(r!=0)if(str[r-1].at(c)=='#')tmp++;//上
                if(r!=0&&c!=w-1)if(str[r-1].at(c+1)=='#')tmp++;//右上
                if(c!=w-1)if(str[r].at(c+1)=='#')tmp++;//右横
                if(r!=h-1&&c!=w-1)if(str[r+1].at(c+1)=='#')tmp++;//右下
                if(r!=h-1)if(str[r+1].at(c)=='#')tmp++;//下
                if(r!=h-1&&c!=0)if(str[r+1].at(c-1)=='#')tmp++;//左下
                if(c!=0)if(str[r].at(c-1)=='#')tmp++;//左横
                str[r].at(c)=tmp+'0';
            }
        }
    }
    for(int i=0;i<h;i++){
        cout<<str[i]<<endl;
    }
    return 0;
}