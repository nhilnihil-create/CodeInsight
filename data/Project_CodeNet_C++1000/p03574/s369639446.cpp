#include<bits/stdc++.h>
using namespace std;
int row,col;
vector<string> st;
bool exist(int x,int y){
    if(x >= 0 && x <= row && y >= 0 && y <= col ){
        if(st[x][y]=='#') return 1;
        else return 0;
    }
    else return false;
}
int main()
{
    int cnt;
    cin>>row>>col;

    string s;
    for(int i=0;i<row;i++)
    {
        cin>>s;
        st.push_back(s);
    }

    for(int i=0;i<row-1;i++) {
        for(int j=0;j<col;j++) {
            cnt =0;
            if(st[i][j]=='#') cout<<st[i][j];
            else {
                if(exist(i+1,j+1)) cnt++;//
                if(exist(i+1,j))  cnt++;
                if(exist(i+1,j-1)) cnt++;
                if(exist(i,j+1)) cnt++;
                if(exist(i,j-1)) cnt++;
                if(exist(i-1,j+1)) cnt++;
                if(exist(i-1,j)) cnt++;
                if(exist(i-1,j-1)) cnt++;
                cout<<cnt;
            }
        }
        cout<<endl;
    }
    int i = row-1;
    for(int j=0;j<col;j++) {
        cnt=0;
        if(st[row-1][j]=='#') cout<<st[row-1][j];
        else {
        if(exist(i-1,j-1)) cnt++;
        if(exist(i-1,j)) cnt++;
        if(exist(i-1,j+1)) cnt++;
        if(exist(i,j+1)) cnt++;
        if(exist(i,j-1)) cnt++;
        cout<<cnt;
        }
    }
}
