#include<iostream>
#include<vector>
int N;
std::vector<int> res,six,ans;
int main(){
    std::cin>>N;
    if(N==3){
        std::cout<<"2 3 25"<<std::endl;
        return 0;
    }
    res.push_back(3);
    res.push_back(9);
    for(int i=2;i+2<=30000;i+=6){
        res.push_back(i);
        res.push_back(i+2);
    }
    for(int i=15;i+6<=30000;i+=12){
        res.push_back(i);
        res.push_back(i+6);
    }
    for(int i=6;i<=30000;i+=6){
        six.push_back(i);
    }
    int count=0;
    while(count+2<=N&&count+2<=15000){
        ans.push_back(res[count]);
        ans.push_back(res[count+1]);
        count+=2;
    }
    for(int i=0;i+count+1<=N;i++){
        ans.push_back(six[i]);
    }
    for(int i=0;i<N;i++){
        std::cout<<ans[i];
        if(i!=N-1)std::cout<<" ";
        else std::cout<<std::endl;
    }
    return 0;
}
