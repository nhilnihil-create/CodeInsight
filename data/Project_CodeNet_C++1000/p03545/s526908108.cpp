#include<iostream>
#include<vector>
using namespace std;

bool getSeven(vector<int>v,int index,int result,vector<char>&op)
{
    if(op.size()==4)
    {
        if(result==7)
        {
            cout<<v[0];
            for(int i=1;i<op.size();i++)
            {
                cout<<op[i];
                cout<<v[i];
            }   
            cout<<"=7";
            return true;
        }
        
        else
        return false;
    }
    else
    {
        vector<char>temp=op;
        temp.push_back('+');
        if(getSeven(v,index+1,result+v[index],temp)==true)
        {
            return true;
        }
        temp.pop_back();
        temp.push_back('-');
        if(getSeven(v,index+1,result-v[index],temp)){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(4);
    for(int i=3;i>=0;i--){
        v[i]=n%10;
        n/=10;
    }
    vector<char>op;
    int index=0;
    getSeven(v,0,0,op);
    
}