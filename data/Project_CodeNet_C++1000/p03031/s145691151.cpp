#include<iostream>
#include<vector>

int main(void){
    int n, m;
    std::cin >> n >> m;
    std::vector<int> sw(n);
    std::vector<std::vector<int>> ls;
    ls.resize(m);
    int k;
    for(int i = 0; i < m; i++){
	std::cin >> k;
	ls[i].resize(k);
	for(int j = 0; j < k; j++){
	    int s;
	    std::cin >> s;
	    s--;
	    ls[i][j] = s;
	}
    }
    std::vector<int> p(m);
    for(int i = 0; i < m; i++){
	std::cin >> p[i];
    }

    int ans = 0;
    bool flag;
    for(int i = 0; i < 1<<n; i++){
	flag = 0;
        for(int j = 0; j < n; j++){
            if(i>>j & 1) sw[j] = 1;
            else sw[j] = 0;
        }
        for(int j = 0; j < m; j++){
            int cnt = 0;
            // int x = ls[j].size();
            for(int l = 0; l < ls[j].size(); l++){
		 int swn = ls[j][l];
                 cnt += sw[swn];	
            }
            if(cnt % 2 != p[j]){
                flag = 1;
                break;
            }
        }
        if(!flag) ans++;
    }
    std::cout << ans << std::endl;
    return 0;
}

