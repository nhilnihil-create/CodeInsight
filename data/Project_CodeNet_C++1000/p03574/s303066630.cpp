#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int h, w;
    cin >> h >> w;
    string s, holder = "";
    rep(i, h){
        cin >> s;
        holder += s;
    }

    int count;
    int center;
    bool top, right, bottom, left;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            count = 0;
            center = i * w + j;
            if (holder.at(center) == '.'){
                top = false;
                right = false;
                bottom = false;
                left = false;
                if (j != 0)
                    left = true;
                if (j != w - 1)
                    right = true;
                if (i != 0)
                    top = true;
                if (i != h - 1)
                    bottom = true;
                
                if (left && top)
                    if (holder.size() - 1 >= center - w - 1)
                        if (holder.at(center - w - 1) == '#')
                            count += 1;
                    
                if (top)
                    if (holder.size() - 1 >= center - w)
                        if (holder.at(center - w) == '#')
                            count += 1;
                    
                if (top && right)
                    if (holder.size() - 1 >= center - w + 1)
                        if (holder.at(center - w + 1) == '#')
                            count += 1;
                    
                if (left)
                    if (holder.size() - 1 >= center - 1)
                        if (holder.at(center - 1) == '#')
                            count += 1;
                        
                if (right)
                    if (holder.size() - 1 >= center + 1)
                        if (holder.at(center + 1) == '#')
                            count += 1;
                    
                if (left && bottom)
                    if (holder.size() - 1 >= center + w - 1)
                        if (holder.at(center + w - 1) == '#')
                            count += 1;
                    
                
                if (bottom)
                    if (holder.size() - 1 >= center + w)
                        if (holder.at(center + w) == '#')
                            count += 1;
                
                if (bottom && right)
                    if (holder.size() - 1 >= center + w + 1)
                        if (holder.at(center + w + 1) == '#')
                            count += 1;                 
                
                cout << count;
            }
            else
            {
                cout << '#';
            }
            if (j == w - 1){
                cout << "" << endl;
            }
        }
    }
    
}