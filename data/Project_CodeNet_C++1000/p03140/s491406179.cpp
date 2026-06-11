#include<iostream>
#include<string>

int main()
{
    int n;
    std::cin>>n;
    int ans=0;
    std::string a,b,c;
    std::cin>>a>>b>>c;
    for(int i=0;i<n;i++){
        if(a[i]==b[i]&&b[i]==c[i])continue;
        if(a[i]!=b[i]&&b[i]!=c[i]&&c[i]!=a[i])ans += 2;
        if(a[i]==b[i]&&b[i]!=c[i])ans++;
        if(a[i]!=b[i]&&b[i]==c[i])ans++;
        if(a[i]!=b[i]&&a[i]==c[i])ans++;
    }
    std::cout<<ans<<std::endl;
}