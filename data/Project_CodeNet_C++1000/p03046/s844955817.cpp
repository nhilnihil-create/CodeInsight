#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);std::cout.tie(0);    
    int n,k;
    std::cin>>n>>k;
    if(n==1 && k==0)
        std::cout<<"0 0 1 1\n";
    else if((1<<n)<=k)
        std::cout<<-1<<'\n';
    else {
        std::vector<int> v={k};
        int xs=0;
        for(int i=0;i<(1<<n);++i)
            if(i!=k) {
                v.push_back(i);
                xs^=i;
            }
        if(xs==k) {
            v.push_back(k);
            for(int i=(1<<n)-1;i>=0;--i)
                if(i!=k)
                    v.push_back(i);
            for(int i=0;i<v.size();++i)
                std::cout<<v[i]<<(i+1==v.size()?'\n':' ');
        } else
            std::cout<<-1<<'\n';
    }
    return 0;
}
