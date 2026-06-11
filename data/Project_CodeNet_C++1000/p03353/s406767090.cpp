#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    unordered_set<string>st;
    vector<string>substring;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++){
            string result="";
            if(j-i+1<=k)
            {
                for(int l=i;l<=j;l++)
                {
                    result+=s[l];
                }
                if(result=="")
                {
                    continue;
                }
                else
                {
                    if(st.find(result)==st.end()){
                        substring.push_back(result);
                        st.insert(result);
                    }
                }

            }
            
        }
    }
    sort(substring.begin(),substring.end());
    cout<<substring[k-1];
}