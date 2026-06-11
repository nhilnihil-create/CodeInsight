#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(void){
    // Your code here!
    int n;
    cin>>n;
    
    vector<pair<string,pair<int, int>>> vec;
    for(int i=0;i<n;i++){
        string a;
        int b;
        cin>>a>>b;
        vec.push_back(make_pair(a,make_pair(b,i+1)));
    }
    
sort(vec.begin(), vec.end(), [](auto a, auto b){
   
   if(a.first < b.first)
        return true;
    else{
        if(a.first==b.first)
            {
                if(a.second.first > b.second.first)
                    return true;
            }
    }
    return false;
});
for(int i=0;i<n;++i){
    cout<<vec[i].second.second<<endl;
}
}
