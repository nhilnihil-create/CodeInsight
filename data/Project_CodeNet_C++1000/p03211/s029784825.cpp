            #include <bits/stdc++.h>
            using namespace std;
            int main(){
				string s;
				int ans=1000;
				cin>>s;
				for(int i=0;i<s.size()-2;i++){
					if(abs(753-((s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0'))<ans){
						ans=abs(753-((s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0'));
					}
				}
				cout<<ans<<endl;
        		return(0);
            }