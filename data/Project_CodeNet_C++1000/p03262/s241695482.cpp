#include<iostream>
#include<set>
#include<vector>
using namespace std;
int gcd(int a,int b){
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main(){
    int n,x;
    cin>>n>>x;
    set<int>st;
    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        st.insert(element);
    }
    st.insert(x);
    vector<int>v;
    for(auto it=st.begin();it!=st.end();it++){
        v.push_back(*it);
    }
    int result=v[1]-v[0];
    for(int i=0;i<v.size()-1;i++)
    {
        result=gcd(result,v[i+1]-v[i]);
    }
    cout<<result;
}