#include<bits/stdc++.h>
int main(){
    int n;std::cin>>n;
    std::vector<std::string>s(n);
    for(auto&&t:s)std::cin>>t;
    int ans=0;
    for(int i=0;i<n;i++){
        bool ng=false;
        for(int j=0;j<=n;j++){
            if(j==n){
                ans++;
                break;
            }
            for(int k=j+1;k<n;k++){
                if(s.at(j).at(k)!=s.at(k).at(j)){
                    ng=true;
                    break;
                }
            }
            if(ng)break;
        }
        std::rotate(s.begin(),s.begin()+1,s.end());
    }
    std::cout<<ans*n<<std::endl;
}

