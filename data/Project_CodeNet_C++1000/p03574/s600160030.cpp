#include <bits/stdc++.h>

using namespace std;


int H, W;
char getElement(vector<string> S, int h, int w){
    if( h >= 0 && h < H && w >= 0 && w < W ){
        return S[h][w];
    } else {
        return '0';
    }
}

int main(int argc, char const *argv[])
{
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; i++)
    {
        cin >> S[i];
    }

    for(int h = 0; h < H; h++){
        string s = "";
        for(int w = 0; w < W; w++){
            if(S[h][w] == '#') {
                s.append("#");
                continue;
            } else {
                int cnt = 0;
                if(getElement(S,h-1,w) == '#') cnt++;
                if(getElement(S,h-1,w-1) == '#') cnt++;
                if(getElement(S,h-1,w+1) == '#') cnt++;
                if(getElement(S,h,w-1) == '#') cnt++;
                if(getElement(S,h,w+1) == '#') cnt++;
                if(getElement(S,h+1,w) == '#') cnt++;
                if(getElement(S,h+1,w-1) == '#') cnt++;
                if(getElement(S,h+1,w+1) == '#') cnt++;

                s.append(to_string(cnt));
            }
        }
        cout << s << endl;
    }
    
    return 0;
}

