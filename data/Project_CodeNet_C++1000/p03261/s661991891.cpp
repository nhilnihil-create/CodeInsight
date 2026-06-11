#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    string prev=v[0];
    bool no=false;
    unordered_set<string>us;
    for(int i=0;i<n;i++){
        if(i!=0){
            if(prev[prev.size()-1]!=v[i][0]){
                no=true;
                break;
            }
            else
            {
                prev=v[i];
            }
        }
        if(us.find(v[i])==us.end()){
            us.insert(v[i]);
        }
        else
        {
            no=true;
            break;
        }
    }
    if(no){
        cout<<"No\n";
    }
    else{
        cout<<"Yes\n";
    }
}